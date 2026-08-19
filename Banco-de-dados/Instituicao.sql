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
