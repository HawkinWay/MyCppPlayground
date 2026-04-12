## change the branch name

```bash
git branch -m learned-to-4.0.2 learned-to-5.15
git fetch origin
git branch -u origin/learned-to-5.15 learned-to-5.15
git remote set-head origin -a
```

## add all renamed or moved files

```bash
git add -A
```
