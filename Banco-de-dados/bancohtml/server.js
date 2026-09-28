const express = require('express');
const cors = require('cors');
const { Pool } = require('pg');
const path = require('path');

const app = express();

app.use(cors());
app.use(express.json());
app.use(express.static(__dirname));

const pool = new Pool({
  user: 'postgres',
  host: 'localhost',
  database: 'Estoque',
  password: 'admin',
  port: 5432,
});

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

app.get('/api/estoque', async (req, res) => {
  try {
    const resultado = await pool.query('SELECT * FROM estoque ORDER BY codigo ASC');
    res.json(resultado.rows);
  } catch (err) {
    res.status(500).json({ erro: err.message });
  }
});

app.post('/api/estoque', async (req, res) => {
  try {
    const { produto, quantidade, preco_unitario } = req.body;
    await pool.query(
      'INSERT INTO estoque (produto, quantidade, preco_unitario) VALUES ($1, $2, $3)',
      [produto, quantidade, preco_unitario]
    );
    res.status(201).send('Inserido com sucesso');
  } catch (err) {
    res.status(500).json({ erro: err.message });
  }
});

app.put('/api/estoque/:codigo', async (req, res) => {
  try {
    const { codigo } = req.params;
    const { produto, quantidade, preco_unitario } = req.body;
    await pool.query(
      'UPDATE estoque SET produto = $1, quantidade = $2, preco_unitario = $3 WHERE codigo = $4',
      [produto, quantidade, preco_unitario, codigo]
    );
    res.send('Atualizado com sucesso');
  } catch (err) {
    res.status(500).json({ erro: err.message });
  }
});

app.delete('/api/estoque/:codigo', async (req, res) => {
  try {
    const { codigo } = req.params;
    await pool.query('DELETE FROM estoque WHERE codigo = $1', [codigo]);
    res.send('Deletado com sucesso');
  } catch (err) {
    res.status(500).json({ erro: err.message });
  }
});

app.listen(3000, () => {
  console.log('--- SERVIDOR NOVO FUNCIONANDO ---');
  console.log('Acesse: http://localhost:3000');
});
