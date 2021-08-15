const path = require('path');

module.exports = {
  mode: 'development',
  entry: './src/main.js',
  output: {
    filename: 'bundle.js',
    path: path.resolve(__dirname, 'dist'),
  },

  // for node-loader
  target: 'node',
  node: {
    __dirname: false
  },
  module: {
    rules: [
      {
        test: /\.node$/,
        exclude: /(node_modules)/,
        loader: "node-loader",
      },

      // for babel
      {
        test: /\.js$/,
        exclude: /(node_modules)/,
        use: {
          loader: "babel-loader",
          options: {
            presets: ["@babel/preset-env"]
          }
        }
      }

    ],
  },

};