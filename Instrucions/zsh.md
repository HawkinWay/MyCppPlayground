# Command Line

## 1. clear your Terminal

```zsh
clear
```

---

## 2. move files

> '.' means current folder  
> '..' means parent folder

### 2.1 change file format

> for example, in the following situation(.txt -> .md)

```zsh
mv fileName.txt fileName.md
```

### 2.2 move file in another folder

```zsh
mv fileName.txt folderName
```

### 2.3 move folder in another folder

```zsh
mv folderName1 folderName2
```

### 2.4 move all files in the subfolder to the parent folder

```zsh
mv subFolder/* parentFolder
```

---

## 3. view file contents

```zsh
cat fileName
```

### 3.1 with line numbers

```zsh
cat -n fileName
```
