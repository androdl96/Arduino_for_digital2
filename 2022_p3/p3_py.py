import serial

ser=serial.Serial('COM3',9600)
sentido = input(" Introduzca FORWARD or BACKWARD si la base se va a mover a favor de las manecillas del reloj o en contra \ n")
sustant = input("Introduzca el numero de sustancias \ n")
ciclos = input ("Introduzca el numero de ciclos a realizar \ n")
inside = input ("Introduzca el tiempo que van a pasar las placas en las sustancias en milisegundos \ n")
dist = float(input("Introduzca la distancia en cm que bajara la placa \ n"))
dist = int (0.367774117921984 + 23.567312537886814*dist)
ser.write((f"{sentido},{sustant},{ciclos},{inside},{dist}").encode('ascii'))
ser.close