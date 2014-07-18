import os

def get_files(folder, found, include):
    for f in os.listdir(folder):
        if os.path.isdir(os.path.join(folder, f)):
            get_files(os.path.join(folder, f), found, include)
        elif os.path.splitext(f)[1] in include:
            found.append(os.path.join(folder, f))
    return found

for filename in get_files('.', [], ['.hpp', '.cpp']):
    with open(filename, 'r') as f:
        c = f.read()
    with open(filename, 'w') as f:
        f.write(c.replace('\r', '\n'))
