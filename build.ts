import {execSync, spawn} from "child_process";
import * as fs from "fs";

import * as path from "path";

const appPath = 'build/SimpleApp_artefacts/Debug/Simple App.app/Contents/MacOS/Simple App';

execSync("cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug", { stdio: "inherit" });

console.log("Compilation du projet...");
execSync("cmake --build build --config Debug", { stdio: "inherit" });

console.log("Lancement de l'application...");
spawn(path.resolve(__dirname, appPath), { stdio: "inherit" });