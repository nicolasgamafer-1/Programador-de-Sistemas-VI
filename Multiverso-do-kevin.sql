CREATE TABLE dimencao
(
	id serial PRIMARY KEY,
	nome varchar NOT NULL
);

CREATE TABLE Registro_de_vida
(
	id serial PRIMARY KEY,
	id_dimencao_FK int, FOREIGN KEY (id_dimencao_FK) REFERENCES dimencao (id),
	nome varchar(100) NOT NULL,
	omega float NOT NULL
);

INSERT INTO dimencao (id, nome) VALUES
(1, 'C875'),
(2, 'C774'),
(3, 'C999'),
(4, 'C321');

INSERT INTO Registro_de_vida (id, nome, omega, id_dimencao_FK) VALUES
(1, 'Douglas Gabriel Ribeiro Avila', 0.742, 1),
(2, 'Douglas Ribeiro Avila', 0.531, 1),
(3, 'Douglas G. Ribeiro Avila', 0.864, 2),
(4, 'Igor Antonio de Almeida', 0.425, 1),
(5, 'Igor Almeida', 0.782, 2),
(6, 'Igor Antonio de Almeida', 0.316, 2),
(7, 'João Gabriel Alves Garlet', 0.653, 1),
(8, 'João Gabriel Garlet', 0.287, 2),
(9, 'João G. Alves Garlet', 0.915, 3),
(10, 'Luiz Carlos vescovi', 0.478, 2),
(11, 'Luiz vescovi', 0.694, 1),
(12, 'Luiz C. Carlos vescovi', 0.352, 4),
(13, 'Marcos Samuel Rodrigues', 0.821, 1),
(14, 'Marcos Rodrigues', 0.264, 2),
(15, 'Marcos S. Rodrigues', 0.573, 3),
(16, 'Nicolas Gabriel Marchi Ferreira', 0.391, 2),
(17, 'Nicolas Marchi Ferreira', 0.728, 1),
(18, 'Nicolas Gabriel Ferreira', 0.612, 4),
(19, 'Ana Cristina Souza', 0.452, 1),
(20, 'Fernanda Oliveira', 0.537, 2),
(21, 'Acassio Pereira', 0.683, 3),
(22, 'Ariel Santos', 0.349, 4),
(23, 'Gabriel Alves', 0.771, 1),
(24, 'Marcos Antonio', 0.498, 2);

SELECT 
r.nome, 
d.nome AS dimensao, 
r.omega, 
	ROUND(CAST(r.omega * 1.618 AS numeric), 3) AS N 
FROM Registro_de_vida AS r 
JOIN dimencao AS d ON r.id_dimencao_FK = d.id 
WHERE d.id IN (1, 2) AND (
r.nome LIKE 'Douglas%' OR 
r.nome LIKE 'Igor%' OR 
r.nome LIKE 'João%' OR 
r.nome LIKE 'Luiz%' OR 
r.nome LIKE 'Marcos%' OR 
r.nome LIKE 'Nicolas%'
) 
ORDER BY N DESC;
