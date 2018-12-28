# Build in docker

### Docker
```
docker run -it -v "$(pwd)":/go/src golang:1.11 bash
```

### Release Build
```
go build -ldflags "-s -w" hello.go
```