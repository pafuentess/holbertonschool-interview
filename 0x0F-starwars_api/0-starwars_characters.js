#!/usr/bin/node

const request = require('request');
const MovieNumber = process.argv.slice(2);

if (Number.isInteger(parseInt(MovieNumber[0]))) {
  request('https://swapi.dev/api/films/' + MovieNumber[0],
    async (error, response, body) => {
      if (error) console.error('error:', error);
      const linksNames = JSON.parse(body).characters;
      for (let index = 0; index < linksNames.length; index++) {
        const name = await Name(linksNames[index]);
        console.log(name);
      }
    });
}

function Name (Namelink) {
  const name = new Promise(
    (resolve, reject) => {
      request(Namelink, (error, response, body) => {
        if (error) console.error('error:', error);
        resolve(JSON.parse(body).name);
      });
    });
  return name;
}
