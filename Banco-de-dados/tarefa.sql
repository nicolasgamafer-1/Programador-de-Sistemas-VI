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

SELECT a.nome, cidade, c.nome, c.carga_horaria FROM alunos AS a 
INNER JOIN cursos AS c ON c.id = a.curso_id;

