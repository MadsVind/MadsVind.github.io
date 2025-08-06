import json
dict = {}

with open("unicode-math-table.tex") as f:
  for line in f:
    split = line.split("\"")[1].split("}")
    utf_code = "\\U" + split[0]
    latex_command = split[1].split(" ")[0][1:]
    dict[latex_command] = utf_code 

with open('latex_utf.json', 'w') as fp:
    json.dump(dict, fp)