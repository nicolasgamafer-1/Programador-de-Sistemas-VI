CREATE TABLE alunos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100),
    idade INT,
    cidade VARCHAR(50),
    curso VARCHAR(50),
    nota NUMERIC(4,2)
);

INSERT INTO alunos (nome, idade, cidade, curso, nota) VALUES
('Ana Silva', 18, 'Curitiba', 'Programação', 8.5),
('Bruno Santos', 21, 'Londrina', 'Redes', 7.0),
('Carlos Souza', 19, 'Curitiba', 'Programação', 9.0),
('Daniel Oliveira', 25, 'Maringá', 'Banco de Dados', 6.5),
('Eduarda Lima', 20, 'Curitiba', 'Redes', 8.0),
('Felipe Costa', 17, 'Londrina', 'Programação', 5.5),
('Gabriela Alves', 22, 'Maringá', 'Banco de Dados', 9.5),
('Henrique Rocha', 19, 'Curitiba', 'Redes', 7.5),
('Isabela Martins', 20, 'Londrina', 'Programação', 8.8),
('João Pereira', 23, 'Curitiba', 'Banco de Dados', 6.0),
('Karen Mendes', 18, 'Maringá', 'Programação', 9.2),
('Lucas Ferreira', 26, 'Curitiba', 'Redes', 7.8);

SELECT * FROM alunos;

SELECT nome, idade, curso FROM alunos;

SELECT nome, cidade FROM alunos;

SELECT nome, idade +1 AS idade_futura
FROM alunos;

SELECT * FROM alunos 
WHERE idade >= 18;

SELECT * FROM alunos 
WHERE cidade ='Curitiba';

SELECT * FROM alunos 
WHERE nota > 8;

SELECT * FROM alunos 
WHERE NOT cidade ='Curitiba';

SELECT * FROM alunos 
WHERE curso ='Programação'
AND idade >= 18;

SELECT * FROM alunos 
WHERE cidade ='Curitiba'
OR cidade = 'Londrina';

SELECT * FROM alunos 
WHERE cidade = 'Curitiba'
AND nota >= 8;

SELECT * FROM alunos 
WHERE idade BETWEEN 18 AND 20;

SELECT * FROM alunos 
WHERE nota BETWEEN 7 AND 9;

SELECT * FROM alunos 
WHERE curso IN ('Programação', 'Redes');

SELECT * FROM alunos 
WHERE cidade IN ('Curitiba', 'Londrina', 'Maringá');


SELECT * FROM alunos 
WHERE nome LIKE 'A%';

SELECT * FROM alunos 
WHERE nome LIKE '%a';

SELECT * FROM alunos 
WHERE nome LIKE '%ana%';

SELECT * FROM alunos 
WHERE nome ILIKE 'c%';

SELECT DISTINCT cidade
FROM alunos;

SELECT DISTINCT curso
FROM alunos;

SELECT * FROM alunos 
ORDER BY nome ASC;

SELECT * FROM alunos 
ORDER BY idade ASC;

SELECT * FROM alunos 
ORDER BY idade DESC;

SELECT * FROM alunos 
ORDER BY cidade ASC, nome ASC;

SELECT * FROM alunos
LIMIT 5;

SELECT * FROM alunos
ORDER BY nota DESC
LIMIT 5;

SELECT * FROM alunos
LIMIT 3
OFFSET 3;

SELECT COUNT(*) AS qnt
FROM alunos;

SELECT COUNT(*) AS qnt
FROM alunos
WHERE curso = 'Programação';

SELECT AVG (idade) AS media
FROM alunos;

SELECT MAX (nota) AS maior
FROM alunos;

SELECT MIN (nota) AS menor
FROM alunos;

SELECT SUM (nota) AS soma
FROM alunos;

SELECT MIN (nota) AS maior,
	   MAX (nota) AS menor,
	   AVG (nota) AS media
FROM alunos;

SELECT cidade, COUNT(*) AS quantidade
FROM alunos
GROUP BY cidade;

SELECT cidade, AVG(nota) AS media
FROM alunos
GROUP BY cidade;

SELECT cidade, MAX(nota) AS maior
FROM alunos
GROUP BY cidade;

SELECT cidade, COUNT(*) AS quantidade
FROM alunos
GROUP BY cidade
HAVING COUNT(*) >= 3;

SELECT cidade, COUNT(*) AS quantidade
FROM alunos
GROUP BY cidade
HAVING COUNT(*) > 3;

SELECT curso, AVG(nota) AS media
FROM alunos
GROUP BY curso
HAVING AVG (nota) > 7;

SELECT cidade, COUNT(*) AS quantidade, AVG (nota) AS media FROM alunos
GROUP BY cidade
HAVING COUNT (cidade) >= 3 AND AVG (nota) > 7
ORDER BY media DESC;

SELECT nome, idade, nota
FROM alunos
WHERE curso = 'Programação'
AND nota >= 7
ORDER BY nota DESC
LIMIT 3;

