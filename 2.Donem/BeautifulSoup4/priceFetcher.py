import requests
from bs4 import BeautifulSoup
import re


class NewEggPriceFetcher:
    def get_document(self, search_term="", go_to_page=1):
        url = f"https://www.newegg.com/p/pl?d={search_term}&N=4131&page={go_to_page}"
        page = requests.get(url).text
        document_name = BeautifulSoup(page, "html.parser")
        return document_name

    def get_page_number(self, search_term):
        page_number_full_text = self.get_document(search_term).find(class_="list-tool-pagination-text").strong.text
        page_number_divider_index = page_number_full_text.find("/")
        page_number = int(page_number_full_text[page_number_divider_index+1:])
        return page_number

    def traverse_pages(self, search_term):
        page_number = self.get_page_number(search_term)
        items = list()
        for current_page in range(1, page_number + 1):
            tmp = self.get_document(search_term, current_page)
            content_html_class = "item-cells-wrap border-cells items-grid-view four-cells expulsion-one-cell"
            items.extend(tmp.find(class_=content_html_class).find_all(text=re.compile(search_term, re.IGNORECASE)))
        return items

    def find_price_dictionary(self, search_term):
        item_list = self.traverse_pages(search_term)
        price_dictionary = dict()
        for item in item_list:
            parent_tag = item.parent
            if parent_tag.name != "a":
                continue
            link = parent_tag["href"].replace(" ", "+")
            price_container = item.find_parent(class_="item-container").find(class_="price-current")
            try:
                price = float(f"{price_container.strong.text.replace(',', '')}{price_container.sup.text}")
            except AttributeError:
                price_container = item.find_parent(class_="item-container").find(class_="price-was-data")
                price = float(f"{price_container.text.replace('$' or ',', '')}")
                item = "!!!Old Price!!! " + item
            price_dictionary[item] = {"price": price, "link": link}
        return price_dictionary

    def sort_price_dictionary(self, search_term):
        price_dictionary = self.find_price_dictionary(search_term)
        sorted_price_list = sorted(price_dictionary.items(), key=lambda x: x[1]["price"])
        # sorted into a list
        return sorted_price_list

    def print_prices(self, search_term):
        sorted_prices = self.sort_price_dictionary(search_term)
        if len(sorted_prices) == 0:
            return "Nothing Found!"
        print("-" * 300)
        for i, item in enumerate(sorted_prices):
            print(f"{i+1}:   {item[0]}: ${item[1]['price']} | {item[1]['link']}")
            print("-" * 300)


class GetExchangeRate:
    def get_document(self):
        currencyFrom = input("From: ").upper()
        currencyTo = input("To: ").upper()
        amount = input("Amount: ")
        url = f"https://www.x-rates.com/calculator/?from={currencyFrom}&to={currencyTo}&amount={amount}"
        page = requests.get(url).text
        document = BeautifulSoup(page, "html.parser")
        return document


    def get_price(self):
        htmlDocument = self.get_document()
        price = htmlDocument.find(class_="ccOutputTxt").text + " " + htmlDocument.find(class_="ccOutputRslt").text
        return price


product = input("What product do you want to search for? ")
newEggPrice = NewEggPriceFetcher()
newEggPrice.print_prices(product)


