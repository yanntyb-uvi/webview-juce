import './style.css'
// @ts-ignore
import {getNativeFunction} from "../juce/index.js";
const ping = getNativeFunction("ping");

const button = document.querySelector("button");
button?.addEventListener("click", () => {
    ping().then((value: string) => document.body.innerHTML = value );
})

