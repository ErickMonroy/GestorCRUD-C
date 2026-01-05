


<div align="center">
  <h1>🗂️ GestorCRUD-C</h1>
  
  <h3>Sistema de Gestión de Registros </h3>
  
  <img src="https://img.shields.io/badge/Lenguaje-C-blue?style=for-the-badge&logo=c" alt="Lenguaje C">
  <img src="https://img.shields.io/badge/Version-1.1.0-green?style=for-the-badge" alt="Versión">
 
  <img src="https://img.shields.io/badge/CRUD-TXT-lightgrey?style=for-the-badge" alt="Versión">
<p align="right"><br>Fecha: 27 de julio de 2023</p>
</div>


## Descripción
<p style="text-align: justify;"> <strong> GestorCRUD-C </strong> es un sistema completo de gestión de registros personales implementado en <strong> lenguaje C</strong>, que permite realizar operaciones CRUD (Crear, Leer, Actualizar, Eliminar) con persistencia de datos en archivos de texto. </p>

## Interfaz del sistema
<div align="center">

 ![Demo del Gestor CRUD en C](https://github.com/ErickMonroy/GestorCRUD-C/blob/main/img_README/GestorCRUD-C.gif?raw=true)

</div>

## Funcionalidades del sistema
- **Agregar registro:** Permite capturar datos personales y almacenarlos al final del archivo `registro.txt.`
- **Actualizar registro:** Busca un folio específico y si existe, solicita los nuevos datos para sobrescribir la información anterior.
- **Eliminar registro:**  Busca un folio y lo remueve permanentemente del archivo.
- **Validaciones:** El sistema verifica la existencia del registro antes de proceder con actualizaciones o bajas. 


## Requisitos Técnicos
Para compilar y ejecutar este programa, asegúrate de tener:
- Un compilador de C (GCC, Clang o el incluido en IDEs como Dev-C++).
- Librerías estándar utilizadas:
  - `<stdio.h>` Manejo de entrada/salida y archivos.
  - `<stdlib.h>` Gestión de procesos y memoria.
  - `<string.h>` Manipulación de cadenas.
  - `<locale.h>` Configuración de idioma (soporte para caracteres en español).



