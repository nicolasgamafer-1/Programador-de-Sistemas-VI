const express = require('express');
const cors = require('cors');
const { Pool } = require('pg');
const path = require('path');

const app = express();
const PORT = 3000;

app.use(cors());
app.use(express.json());

// Serve os arquivos da pasta atual (incluindo index.html)
app.use(express.static(__dirname));

// Configuração do PostgreSQL
const pool = new Pool({
  user: 'postgres',
  host: 'localhost',
  database: 'Estoque',
  password: 'admin',
  port: 5432,
});

// Rota para a página inicial
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

// Rota SELECT
app.get('/api/estoque', async (req, res) => {
  try {
    const resultado = await pool.query('SELECT * FROM estoque ORDER BY codigo ASC');
    res.json(resultado.rows);
  } catch (err) {
    res.status(500).json({ erro: err.message });
  }
});

app.listen(PORT, () => {
  console.log(`🚀 SERVIDOR NOVO RODANDO EM: http://localhost:${PORT}`);
});