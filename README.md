# TestingSoftwareTP3 version B 
## Trabajo práctico 3. Testing unitario.
- Seleccionar una biblioteca (o componente) del software a desarrollar en el TP final de la
carrera de especialización / maestría y escribir un test unitario con ceedling que incluya por
lo menos 5 test cases. El archivo de test debe tener por lo menos 65 líneas de extensión
Se debe mantener bajo control de versión el código generado.
# Entregar:
- Repositorio con el archivo con las pruebas unitarias y el código de producción bajo prueba
(preferentemente en bitbucket o github).
Se debe probar AHT10.c utilizando un mock de AHT10_port.c. Se llama a una función AHT10_Init(), y se revisa que se transmíten las tramas correctas por I2C y se emulan las respuestas que daría el sensor para ver si la función responde como debe.
