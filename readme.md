# Installation de juce

```bash
git submodule add --force https://github.com/juce-framework/JUCE.git libs/juce  &&
git submodule update --init --recursive &&
git add .\gitmodules .\libs\juce 
```
# Lancement du hot reload
```bash
bun ./scripts/build-on-save.ts
```