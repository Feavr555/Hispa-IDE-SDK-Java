# Hispa-IDE-SDK-Java

```
make
```
Compilación cruzada de linux para windows.
Requerimientos:
```
sudo pacman -S mingw-w64
```
```
make linux_shared
```
Compilación para linux.

Una vez compilado, mover el ejecutable bin/debug/sdk a /usr/bin/sdk. 'sdk' -> ejecutable

```
sdk proyecto nuevo [name project]
```
Crea proyecto nuevo de java.

```
sdk package [name pack] [name class]
```
Entre en la carpeta de su proyecto java, y ejecute el comando para agregar paquetes y clases,
si el paquete ya existe, agrega la clase en el paquete.

```
sdk build
```
Compila los .java a .class en el directorio bin/ respetando los paquetes.

```
sdk jar
```
Arma un .jar a partir de los .class en el directorio export/program.jar

```
sdk run
```
Ejecuta el .jar, con "java -jar export/program.jar" ejecutas tu ejecutable .jar

```
sdk build run
```
Compilas y ejecutas los .class












