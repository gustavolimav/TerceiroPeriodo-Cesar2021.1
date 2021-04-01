# Questão 1

Codifique as 3 classes apresentadas no diagrama biblioteca.png, identifique as coleções corretas para os atributos presentes no diagrama listados abaixo:

 Livro.autores: coleção de autores (do tipo Autor) que preserva a ordem da inserção, ex.: autor 1, autor 2, autor 3, ...
 Livro.tags: coleção das tags (do tipo String), ordenação não é importante e não deve ser possível cadastrar tags duplicadas
 Autor.obras: coleção das obras de um autor, não é necessário preservar a ordem e não deve ser possível cadastrar obras (Livros) duplicadas
 Catalogo.livros: coleção que deve permitir recuperar um Livro a partir do ISBN (String)

 O atributo isbn é o identificador de um livro, assim como o cpf identifica um autor.

 Lembrem de estruturar o projeto em pacotes e seguir as convenções de codificação do Java apresentadas em sala de aula.