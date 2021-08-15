
## how to use

### build, bundle, test
- `yarn build && yarn transpile-and-bundle && yarn test`

## history

### add babel for es6
- `yarn add -D @babel/cli @babel/preset-env` for minimal babel
- `yarn add -D babel-loader @babel/core` to transpile via webpack

### add webpack
- `yarn add -D webpack webpack-cli node-loader`
- `touch webpack.config.js`
- move addon.js to src, rename to main.js
- require statement now requires `.node` extension

### bare minimum node-api example
- `.vscode/c_cpp_propeties` may need to be adjusted to find node_api.h