const Sequelize = require('sequelize')
const config = require('config')

const instancia = new Sequelize(
    config.get('mysql.banco-de-dados'),
    config.get('mysql.usuario'),
    config.get('mysql.senha'),
    {
        host: '127.0.0.1',
        dialect: 'mysql'
    }
)