from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
plt.rcParams['figure.figsize'] = [20, 20]


r = np.arange(50, 15000,10) # isik sensorumuzun kac ohm oldugu
R = 5000
V = 5

Vout = V * r / (r+R)
Iout = V/(r+R)

Iouts = Vouts = Rs = rs = []

for Rv in range(5000,15000,1000):  #5k ohm dan 15k ohm a kadar 1k adimlarla direncleri deneyelim.
    
    #Bu Rv degeri ve bunun sensor r leri icin voltajlar
    Vout = V * r / (r+Rv)
    
    #Bu Rv degeri ve bunun sensor r leri icin akimlar
    Iout = V/(r+Rv)
    
    
    # buyuk listelere bu akimlari ve voltajlari ekleyelim.
    Iouts = np.append(Iouts, Iout)
    Vouts = np.append(Vouts, Vout)
    
    # buyuk listelere bu direnc degerini ekleyelim.
    a = np.empty(Vout.size)
    a.fill(Rv) #hepsi ayni Rv degeri
    
    
    Rs = np.append(Rs,a)
    rs = np.append(rs,r)



fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.scatter(rs, Rs,Vouts,  c=Iouts,s=20, marker='o')


ax.set_xlabel('Sensor (Ohm)')
ax.set_ylabel('Direnc (Ohm)')
ax.set_zlabel('V')

plt.show()


