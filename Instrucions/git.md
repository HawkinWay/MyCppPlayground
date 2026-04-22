## 1. change the branch name

```bash
git branch -m learned-to-4.0.2 learned-to-5.15
git fetch origin
git branch -u origin/learned-to-5.15 learned-to-5.15
git remote set-head origin -a
```

---

## 2. add all renamed or moved files

```bash
git add -A
```

---

## 3. create a new repository and push from local

3.1. **local**

```bash
git init
git add .
git commit -m "initial commit"
```

3.2. **github.com**

&emsp;3.2.1. create a new repository  
&emsp;3.2.2. **DO NOT** select any "Initialize this repository with..."(*README* or &emsp;*.gitignore*)  
&emsp;3.2.3. copy the SSH address (git@github.com:HawkinWay/xxx.git)  

3.3. **remote and push**

```bash
git remote add origin git@github.com:HawkinWay/xxx.git
# use -M to unify naming
git branch -M main
# when you first push into your new branch, use '-u' to establish association
git push -u origin main
```

3.4. **issues**

3.4.1. Permission denied(publickey)

> No boarding pass or computer key.

```bash
cat ~/.ssh/id_ed25519.pub
```

3.4.2. non-fast-forward

> Remotely stored files (e.g., readme).
```bash
git push origin main --rebase
```

3.4.3. unrelated-histories

> Local and remote records each have their own history.

```bash
git pull origin main --allow-unrelated-histories
```
