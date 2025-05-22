# 🧮 Calculadora Simples - Qt + C++

Este é um projeto simples de uma calculadora gráfica desenvolvido com **Qt Creator** e **C++**, ideal para fins de aprendizado sobre:
- Interface gráfica com Qt
- Programação orientada a objetos em C++
- Uso de sinais, slots e funções lambda

---

## 📸 Interface

A calculadora possui uma interface gráfica com os seguintes componentes:
- `QLineEdit`: Para exibir os números digitados e o resultado.
- `QPushButton`: Botões de 0 a 9, operações básicas (`+`, `-`, `*`, `/`), igual (`=`) e limpar (`C`).
- `QGridLayout`: Usado para organizar os botões como um teclado de calculadora.

---

## ⚙️ Funcionalidades

- Entrada de números (0–9)
- Operações matemáticas básicas: adição, subtração, multiplicação e divisão
- Exibição do resultado com o botão `=`
- Botão `C` para limpar tudo

---

## 🧠 Tecnologias e Conceitos

- **Qt 5/6 com Qt Creator**
- **C++ moderno (uso de lambdas)**
- **Sinais e slots** com `connect()`
- Organização de variáveis como **atributos privados** da classe
- Separação em arquivos `.h` e `.cpp`
- Validação para **divisão por zero**
