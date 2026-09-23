CREATE TABLE estoque
(
	codigo serial primary key,
	produto varchar (25),
	quantidade int,
	preco_unitario numeric (10,2)
);
