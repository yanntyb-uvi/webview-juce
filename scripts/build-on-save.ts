import * as fs from 'fs';
import * as path from 'path';
import { ChildProcess } from 'node:child_process';
import build from "./build";

let processes: ChildProcess[] = [];


// Fonction pour fermer proprement tous les anciens processus
function terminateProcesses(): void {
   console.log('⏱️ Tentative d’arrêt des processus existants...');
   processes.forEach((p) => {
      if (!p.killed) {
         try {
            // Tenter d’arrêter le processus avec SIGTERM
            process.kill(p.pid as number, 'SIGTERM');
            console.log(`✅ Processus (PID : ${p.pid}) arrêté avec succès.`);
         } catch (err) {
            console.error(`🛑 Erreur lors de l'arrêt du processus (PID : ${p.pid}):`, err);
         }
      }
   });

   // Vider la liste des processus après avoir tenté de les arrêter
   processes.length = 0;
}

// Fonction pour surveiller un répertoire et ses sous-dossiers
function watchDirectory(dir: string): void {
   fs.watch(dir, { recursive: true }, (event, filename) => {
      if (!filename) {
         return;
      }

      console.log(`📂 Changement détecté : ${filename}`);


      const current = build()
      // Arrêter tous les anciens processus avant d'en lancer un nouveau
      terminateProcesses();
      processes.push(current);


   });
}

// Démarrage initial
processes.push(build());

// Surveiller le répertoire pour redémarrer les processus en cas de modification
watchDirectory(path.join(__dirname, '../plugin'));