# Mini Rede Social

Nessa lista vamos implementar um conjunto mínimo de classes que simulam uma rede social capaz de publicar Publicações
e Stories.
O controle das publicações ficará a cargo de uma classe chamada ServicoPublicacao.
A classe Publicacao deverá ter os seguintes atributos:
1. autor: Usuario
2. texto: String
3. tags: List<String> (Calculado a partir do texto)
4. data: Date

A classe Story será uma subclasse de Publicacao que além dos atributos terá um expiracao responsável por anotar o timestamp que o Story deverá ser ocultado.

Já existe um caso de teste para o ServicoPublicacao, observe a implementação do caso de teste e complete o ServicoPublicacao de forma que o caso de teste funcione corretamente.

Complete as classes Publicacao e Usuario e implemente a classe Story de acordo com o diagrama.

Por fim, crie uma classe de teste chamada TestPublicacao com um caso de teste que dada uma publicacao com o texto "Meu primeiro caso de teste #junit #hamcrest #poo #java", este verifica que a publicacao retorna corretamente uma lista no método getTags contento [junit, hamcrest, poo, java] (Dica: utilizem o método split e startsWith da classe String).