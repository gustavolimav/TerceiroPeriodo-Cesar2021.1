# Questão 3
Temos no Java os conceitos de Classes Abstratas e Interfaces. Explique, com suas palavras, ambos os conceitos, suas principais diferenças e aplicações.
## Resposta:

Classe Abstrata: São classes que não permitem realizar nenhuma forma de instância, elas servem de modelo para classes derivadas. Você cria classes abstratas quando você tem herança e ela será herdada por outras classes.

Interface: É um protocolo de comportamento, é um lista de metodos abstratos, que pode incluir variaveis. Para utilizar uma interface é preciso usar uma classe que implemente-a. A classe será obrigada a definir todos os métodos dessa interface.


Uma classe abstrata pode conter código logico e a interface somente pode especificar quais os métodos. Nenhuma das duas pode ser usada para construir um objeto. Por esse motivo a classe abstrata precisa de uma classe que a derive e a interface uma que a implemente.
