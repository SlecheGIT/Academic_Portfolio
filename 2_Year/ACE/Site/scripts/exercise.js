const textarea = document.getElementById("userCode");
const output = document.getElementById("output");
const enter = document.getElementById("enter");

let editor = CodeMirror.fromTextArea(document.getElementById("editor"), {
  mode: "javascript",
  lineNumbers: true,
});

enter.addEventListener("click", () => {
  let codigo = editor.getValue();
  output.textContent = eval(codigo);
});
