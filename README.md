# hhvm-cli-example

## Setup
### Install Docker
See https://docs.docker.com/install/

### Install Docker Compose
See https://docs.docker.com/compose/install/

### Build Docker Container
```bash
$ docker-compose build
```

## Prepare environment
### Create .env file and edit environment variables.
```bash
$ cp .env.example .env
```

- AWS_S3_BUCKET: Input AWS S3 Bucket name.

### Unzip image files
```bash
$ unzip -j -d var/images var/images.zip
```

## Run HHVM Container
```bash
$ docker-compose run --rm hhvm bash
```

### Install packages via Composer
```bash
root@{container ID}:/app# composer install
Writing lock file
Generating autoload files
```

### Execute .hh file
```bash
root@{container ID}:/app# hhvm bin/hello.hh
Hello hacklang.
```
