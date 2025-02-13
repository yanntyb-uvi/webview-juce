import {execSync, spawn} from "child_process";
import * as fs from "fs";

import * as path from "path";

const appPath = path.resolve(__dirname, '../build/SimpleApp_artefacts/Simple App.app/Contents/MacOS/Simple App');


export default function build () {
    console.log("Configuration du projet avec CMake...");
    execSync("cmake -S . -B build", { stdio: "inherit" });
    console.info("Configuration CMake terminée");

    console.log("Compilation du projet...");
    execSync("cmake --build build --config Release", { stdio: "inherit" });
    console.info("Compilation terminée avec succès");

    console.log("Lancement de l'application...");
    return spawn(appPath, { stdio: "inherit" });
};