import os

def file_get_contents(filename):
    with open(filename, 'r') as f:
        return f.read()

def file_put_contents(filename, content):
    with open(filename, 'w') as f:
        f.write(content)

def get_files(folder, found, include):
    for f in os.listdir(folder):
        if os.path.isdir(os.path.join(folder, f)):
            get_files(os.path.join(folder, f), found, include)
        elif os.path.splitext(f)[1] in include:
            found.append(os.path.join(folder, f))
    return found

for f in get_files('.', [], ['.hpp', '.cpp']):
    file_put_contents(f, file_get_contents(f).replace('\r', '\n'))
