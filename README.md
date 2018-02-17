# Codegen example

## Installing packages

```json
"require": {
  "hhvm/hhvm-autoload": "^1.5"
},
"require-dev": {
  "hhpack/codegen": "^0.2.0"
},
```

## Basic usage

```shell
vendor/bin/codegen -h
```

## Generate class file

```shell
vendor/bin/codegen package:class [CLASS_NAME]
```

## Generate test class file

```shell
vendor/bin/codegen package:testclass [TEST_CLASS_NAME]
```
