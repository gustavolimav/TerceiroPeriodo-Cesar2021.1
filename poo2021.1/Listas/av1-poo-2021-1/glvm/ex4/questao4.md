# Questão 4

## Temos duas grandes categorias de exceções no Java, as subclasses de Exception e as subclasses de RuntimeException. Explique, com suas palavras, as principais diferenças de se utilizar cada uma das duas hierarquias, focando, principalmente nas diferenças com relação ao tratamento das duas hierarquias.

# Respota:

Utiliza-se RuntimeException quando a exceção pode ser previnida, ou seja, representa defeitos no programa, por exemplo argumentos inválidos passados, que podem ser resolvidos pelo usuário na hora que a execeção for lançada.

Em relação aos erros que devem ser previnidos usa-se Exception, que é mais geral e pode envolver qualquer exceção. Ela é considerada uma Exceção checada, o que significa que representa condições inválidas em áreas fora do controle imediato do programa (entrada do usuário, banco de dados, falha de rede...).