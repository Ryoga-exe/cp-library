#!/usr/bin/env python3

import os
import glob
import json
import yaml
import sys

OUTPUT_EXTENSION = '.code-snippets'
CONFIG_FILE = './config.yml'

g_ignore = []
g_scope = []

def create_snippet(file_path):
    name = os.path.splitext(os.path.basename(file_path))[0]
    ext = os.path.splitext(os.path.basename(file_path))[1][1:]

    with open(file_path, mode='r') as f:
        text = f.read()
    
    lines = text.replace('/** ', '').replace(' **/', '').split('\n')
    
    startline = 0

    options = {}

    for index, line in enumerate(lines):
        if line.strip() == '/// start':
            startline = index + 1
        if line.strip().startswith('/// @'):
            key = line.strip()[5:].split(' ')[0]
            value = line.strip()[5 + len(key) + 1:]
            if key == 'isFileTemplate':
                if value == 'true':
                    options[key] = True
                else :
                    options[key] = False
            else :
                options[key] = value.replace('\\n', '\n')
    
    snippet = {
        'prefix': options.get('prefix', name),
        'body': [s for s in lines[startline:] if not s.startswith('/// @')],
        'description': options.get('description', name),
        'scope': g_scope.get(ext, ext),
        'isFileTemplate': options.get('isFileTemplate', False)
    }
    return snippet

def create_snippets(dir_name):
    snippets = {}

    ignore_files = glob.glob("!*")

    for ignore in g_ignore:
        ignore_files.extend(glob.glob(os.path.join(dir_name, ignore), recursive=True))

    for file_path in glob.iglob(os.path.join(dir_name, '**', '*'), recursive=True):
        if file_path in ignore_files:
            continue
        
        if os.path.isfile(file_path):
            file_name = os.path.basename(file_path)
            ext = os.path.splitext(file_path)[1]
            snippets[file_name] = create_snippet(file_path)

    return snippets

def write_file(snippets, directory, filename):
    output = str(os.path.join(directory, filename))
    os.makedirs(directory, exist_ok=True)
    with open(output, mode='w') as f:
        f.write(json.dumps(snippets, ensure_ascii=False, indent=4))

if __name__ == '__main__':
    with open(CONFIG_FILE) as file:
        config = yaml.safe_load(file)
    
    config_general = config.get('config', 'None')
    config_scope = config.get('scope', 'None')
    config_snippet = config.get('snippet', 'None')

    build_dir = './'

    if config_general != 'None':
        build_dir = config_general.get('build-dir', './')
        g_ignore = config_general.get('ignore', [])
    
    if config_scope != 'None':
        g_scope = config_scope
    
    if config_snippet != 'None':
        for item in config_snippet:
            for group, dir_name in item.items():
                snippets = create_snippets(dir_name)
                filename = group + OUTPUT_EXTENSION

                if type(build_dir) is str:
                    write_file(snippets, build_dir, filename)
                elif type(build_dir) is list:
                    for directory in build_dir:
                        write_file(snippets, directory, filename)

                print("Created", filename, "from", dir_name)
 