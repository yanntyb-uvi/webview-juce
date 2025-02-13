import {execSync, spawn} from "child_process";
import * as fs from "fs";

import * as path from "path";

const appPath = './build/SimpleApp_artefacts/Simple App.app/Contents/MacOS/Simple App';

execSync("cmake -S . -B build", { stdio: "inherit" });

console.log("Compilation du projet...");
execSync("cmake --build build --config Release", { stdio: "inherit" });

console.log("Lancement de l'application...");
spawn(path.resolve(__dirname, appPath), { stdio: "inherit" });