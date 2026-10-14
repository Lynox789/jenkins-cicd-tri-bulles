# jenkins-cicd-tri-bulles

Projet BUT3 « Qualité de développement » : chaîne CI/CD Jenkins (option 1 : Dev, Pré-prod, Prod) autour d'un tri à bulles en C.

## Structure

| Chemin | Rôle |
|---|---|
| `src/` | `tri_bulles.c/.h` (fonction de tri) et `main.c` (programme) |
| `tests/test_tri_bulles.c` | tests (code retour ≠ 0 si un test échoue) |
| `Makefile` | `make`, `make test`, `make install PREFIX=...`, `make clean` |
| `dev/Jenkinsfile` | pipeline Dev/Tests |
| `preprod/Jenkinsfile` | pipeline Pré-prod (Valgrind : memcheck, callgrind, massif) |
| `prod/Jenkinsfile` | pipeline Prod (make clean, strip, make install) |

## Utilisation locale

```bash
make && make test && ./tri_bulles 1000
```

## Jenkins : un job par pipeline

Nouveau job → **Pipeline** → *Pipeline script from SCM* → Git (URL du dépôt, branche `*/main`) → **Script Path** : `dev/Jenkinsfile`, `preprod/Jenkinsfile` ou `prod/Jenkinsfile`.