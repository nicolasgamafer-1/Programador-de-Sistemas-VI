CREATE TABLE departamento
(
	codigo_departamento SERIAL PRIMARY KEY,
	nome varchar(100) NOT NULL,
	area_atucao varchar(100) NOT NULL
);

CREATE TABLE evento
(
codigo_evento SERIAL PRIMARY KEY,
nome VARCHAR(150) NOT NULL,
descricao TEXT,
data_realizacao DATE NOT NULL,
carga_horaria INT NOT NULL,
codigo_departamento_FK int, FOREIGN KEY (codigo_departamento_FK) REFERENCES departamento (codigo_departamento),
nome_FK VARCHAR(150), FOREIGN KEY (nome_FK) REFERENCES espaco(nome)
);

CREATE TABLE espaco
(
localizacao VARCHAR NOT NULL,
nome VARCHAR(150) PRIMARY KEY,
capacidade_maxima INT NOT NULL
);

CREATE TABLE evento_aluno
(
codigo_evento_FK INT, FOREIGN KEY (codigo_evento_FK) REFERENCES evento(codigo_evento),
numero_matricula_FK INT, FOREIGN KEY (numero_matricula_FK) REFERENCES aluno(numero_matricula)
);

CREATE TABLE aluno
(
nome VARCHAR NOT NULL,
numero_matricula SERIAL PRIMARY KEY,
e_mail VARCHAR NOT NULL,
curso VARCHAR NOT NULL,
situacao_FK VARCHAR, FOREIGN KEY (situacao_FK) REFERENCES inscricao(situacao)
);

CREATE TABLE inscricao
(
situacao VARCHAR PRIMARY KEY,
data_do_vento DATE NOT NULL,
codigo_unico_FK INT, FOREIGN KEY (codigo_unico_FK) REFERENCES certificado(codigo_unico)
);

CREATE TABLE certificado
(
data_de_emicao DATE NOT NULL,
codigo_unico SERIAL PRIMARY KEY,
carga_horaria INT NOT NULL
);

CREATE TABLE patrocinador
(
nome VARCHAR NOT NULL,
cnpj SERIAL PRIMARY KEY,
cidade_origen VARCHAR NOT NULL,
telefone SERIAL NOT NULL
);

CREATE TABLE evento_patrocinador
(
codigo_evento_FK INT, FOREIGN KEY (codigo_evento_FK) REFERENCES evento(codigo_evento),
cnpj_FK INT, FOREIGN KEY (cnpj_FK) REFERENCES patrocinador(cnpj)
);

CREATE TABLE palestrante
(
nome VARCHAR NOT NULL,
e_mail VARCHAR NOT NULL,
id_palestrante SERIAL PRIMARY KEY,
instituicao_origen VARCHAR NOT NULL,
telefone SERIAL NOT NULL
);

CREATE TABLE evento_palestrante
(
codigo_evento_FK INT, FOREIGN KEY (codigo_evento_FK) REFERENCES evento(codigo_evento),
id_FK INT, FOREIGN KEY (id_FK) REFERENCES palestrante(id_palestrante)
);

INSERT INTO aluno (nome, numero_matricula, e_mail, curso, SITUACAO_fk)
VALUES ('Henrique', 2026002, 'bili@aluno.senai.br', 'programador de sistemas', 'aprovado');

INSERT INTO aluno (nome, numero_matricula, e_mail, curso, SITUACAO_fk)
VALUES ('lauro', 2026001, 'lauro@gmail.com', 'programador de sistemas', 'aprovado');

INSERT INTO aluno (nome, numero_matricula, e_mail, curso, SITUACAO_fk)
VALUES ('Igor', 2026003, 'ingor@aluno.senai.br', 'programador de sistemas', 'reprovado');

INSERT INTO aluno (nome, numero_matricula, e_mail, curso, SITUACAO_fk)
VALUES ('Cleiton', 2026004, 'cleiton@gmail.com', 'programador de sistemas', 'aprovado');

INSERT INTO aluno (nome, numero_matricula, e_mail, curso, SITUACAO_fk)
VALUES ('Cleverson', 2026005, 'clevson@gmail.com', 'programador de sistemas', 'aprovado');

INSERT INTO aluno (nome, numero_matricula, e_mail, curso, SITUACAO_fk)
VALUES ('Octavio', 2026006, 'octivio@gmail.com', 'programador de sistemas', 'aprovado');

INSERT INTO aluno (nome, numero_matricula, e_mail, curso, SITUACAO_fk)
VALUES ('douglas', 2026007, 'douglos@gmail.com', 'programador de sistemas', 'aprovado');

INSERT INTO aluno (nome, numero_matricula, e_mail, curso, SITUACAO_fk)
VALUES ('yasmin', 2026008, 'jasmini@gmail.com', 'programador de sistemas', 'aprovado');

INSERT INTO aluno (nome, numero_matricula, e_mail, curso, SITUACAO_fk)
VALUES ('ronaldo', 2026009, 'meirelhos@gmail.com', 'programador de sistemas', 'aprovado');

INSERT INTO aluno (nome, numero_matricula, e_mail, curso, SITUACAO_fk)
VALUES ('jonas', 20260010, 'joracildo@gmail.com', 'programador de sistemas', 'aprovado');

INSERT INTO inscricao (situacao, data_do_vento)
VALUES ('reprovado', '2026-08-24');

UPDATE departamento
SET area_atucao = 'alimentação'
WHERE codigo_departamento = 2026100;

table departamento

INSERT INTO departamento (codigo_departamento, nome, area_atucao)
VALUES (2026110, 'alimentos', 'limentação');

INSERT INTO departamento (codigo_departamento, nome, area_atucao)
VALUES (2026120, 'contrução', 'construir');

INSERT INTO departamento (codigo_departamento, nome, area_atucao)
VALUES (2026130, 'financeiro', 'dinheiro');

INSERT INTO departamento (codigo_departamento, nome, area_atucao)
VALUES (2026140, 'academico', 'cuidar dos alunos');

INSERT INTO departamento (codigo_departamento, nome, area_atucao)
VALUES (2026150, 'cotinas', 'corina');

INSERT INTO departamento (codigo_departamento, nome, area_atucao)
VALUES (2026160, 'prograação', 'programar');

INSERT INTO departamento (codigo_departamento, nome, area_atucao)
VALUES (2026170, 'gabriels', 'todos os gabriels');

INSERT INTO departamento (codigo_departamento, nome, area_atucao)
VALUES (2026180, 'teste', 'testes');

INSERT INTO departamento (codigo_departamento, nome, area_atucao)
VALUES (2026190, 'caimento', 'cair');

INSERT INTO departamento (codigo_departamento, nome, area_atucao)
VALUES (2026111, 'orações', 'orar');


