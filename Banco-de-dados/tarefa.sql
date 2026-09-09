CREATE TABLE cursos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    carga_horaria INT NOT NULL
);

CREATE TABLE alunos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    idade INT,
    cidade VARCHAR(50),
    curso_id INT,
    FOREIGN KEY (curso_id) REFERENCES cursos(id)
);

CREATE TABLE alunos_antigos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cidade VARCHAR(50)
);

INSERT INTO cursos (nome, carga_horaria) VALUES
('Programação de Sistemas', 1200),
('Redes de Computadores', 1000),
('Banco de Dados', 800),
('Desenvolvimento Web', 1000),
('Internet das Coisas', 600),
('Eletrônica', 800);

INSERT INTO alunos (nome, idade, cidade, curso_id) VALUES
('Ana Silva', 18, 'Curitiba', 1),
('Bruno Santos', 21, 'Londrina', 2),
('Carlos Souza', 19, 'Curitiba', 1),
('Daniel Oliveira', 25, 'Maringá', 3),
('Eduarda Lima', 20, 'Curitiba', 2),
('Felipe Costa', 17, 'Londrina', 1),
('Gabriela Alves', 22, 'Maringá', 3),
('Henrique Rocha', 19, 'Curitiba', 2),
('Isabela Martins', 20, 'Londrina', 1),
('João Pereira', 23, 'Curitiba', 3),
('Karen Mendes', 18, 'Maringá', NULL),
('Lucas Ferreira', 26, 'Curitiba', 2);

INSERT INTO alunos_antigos (nome, cidade) VALUES
('Marcos Lima', 'Curitiba'),
('Patrícia Souza', 'Londrina'),
('Rafael Costa', 'Maringá'),
('Ana Silva', 'Curitiba'),
('Carlos Souza', 'Curitiba');

SELECT a.nome, c.nome FROM alunos AS a 
INNER JOIN cursos AS c ON c.id = a.curso_id;

SELECT a.nome, cidade, c.nome FROM alunos AS a 
INNER JOIN cursos AS c ON c.id = a.curso_id;

SELECT a.nome, cidade, c.nome, c.carga_horaria FROM alunos AS a 
INNER JOIN cursos AS c ON c.id = a.curso_id;

SELECT a.nome, cidade, c.nome FROM alunos AS a 
INNER JOIN cursos AS c ON c.id = a.curso_id
WHERE c.nome = 'Programação de Sistemas';

SELECT a.nome, cidade, c.nome, c.carga_horaria FROM alunos AS a 
INNER JOIN cursos AS c ON c.id = a.curso_id
WHERE c.carga_horaria >=900;

SELECT a.nome, c.nome
FROM alunos AS a
LEFT JOIN cursos AS c ON c.id = a.curso_id;

/*por que ele trás todos os itens mesmo que não tenham releção
com a outra tabela, esse aluno não tem curso */

SELECT a.nome, c.nome, a.cidade
FROM alunos AS a
LEFT JOIN cursos AS c ON c.id = a.curso_id;

SELECT a.nome, c.nome
FROM alunos AS a
LEFT JOIN cursos AS c ON c.id = a.curso_id
WHERE c.id IS NULL;

SELECT a.nome, c.nome, a.cidade
FROM alunos AS a
LEFT JOIN cursos AS c ON c.id = a.curso_id
WHERE a.cidade = 'Curitiba';

SELECT a.nome, c.nome
FROM alunos AS a
RIGHT JOIN cursos AS c ON c.id = a.curso_id;

/*"Internet das Coisas"
"Eletrônica"
"Desenvolvimento Web"*/

SELECT a.nome, c.nome, c.carga_horaria
FROM alunos AS a
RIGHT JOIN cursos AS c ON c.id = a.curso_id;

/*o inner join pega os dados que tem a igualdade dos dois lados 
e o left join pega todo um lado mesmo que não tenha igualdade dos 
dois lados*/

select nome from alunos
union
select nome from alunos_antigos;

/*eles só aparecem 1 vês, porque o union não deixa repetir dados
que se repetem nas duas tabelas*/

select cidade from alunos
union
select cidade from alunos_antigos;

select nome from alunos
union
select nome from alunos_antigos
ORDER BY nome ASC;

select nome from alunos
union ALL
select nome from alunos_antigos;

/*o union all tem mais, porque ele deixa doplicado oque tem nas 
duas tabelas*/

/*o union pega as informações de 2 tabelas e não deixa elas
se repetirem e o union all deixa*/

/*o join mostra os dados de lado */
/*o union mostra os dados um em baixo do outro*/

/*o join pois mostrara a tabela dos cursos e dos alunos um ao lado do outro*/

/*Ana
Bruno
Carlos
Daniel
Eduarda*/

/*Ana
Bruno
Carlos
Carlos
Daniel
Eduarda*/

SELECT a.nome, cidade, c.nome FROM alunos AS a 
INNER JOIN cursos AS c ON c.id = a.curso_id;

SELECT a.nome, c.nome, c.carga_horaria
FROM alunos AS a
RIGHT JOIN cursos AS c ON c.id = a.curso_id
WHERE a.id IS NULL;

select nome from alunos
union
select nome from alunos_antigos;

select nome from alunos
union all
select nome from alunos_antigos;

