import sublime, sublime_plugin
import os.path
import shutil
import os
import tempfile
import re

# copy file to
# ~/.config/sublime-text-3/Packages/User
#
# in sublime text menu: Preferences -> Key Bindings - User
# [
#     { "keys": ["ctrl+shift+n"], "command": "prompt_codeforces_new_cpp" }
# ]

def create_empty_file(file_name):
    basedir = os.path.dirname(file_name)
    if not os.path.exists(basedir):
        os.makedirs(basedir)        
    open(file_name, 'a').close()

def replaceRegex(file_path, regexp, subst):
    fh, abs_path = tempfile.mkstemp()
    with open(abs_path,'w') as new_file:
        with open(file_path) as old_file:
            for line in old_file:
                new_line = re.sub(regexp,subst,line)
                new_file.write(new_line)
    os.close(fh)
    os.remove(file_path)
    shutil.move(abs_path, file_path)

class CodeforcesNewCppCommand(sublime_plugin.WindowCommand):

    def run(self):
        self.window.show_input_panel("program name:", "", self.on_done, None, None)
        pass

    def on_done(self, text):
        line = text

        codeForcesFolder = "/mnt/programs/programs/learn 2015/learn_algorithms/codeforces_archive/";

        programName = line

        resultFileName = codeForcesFolder+programName+".cpp";
        
        if os.path.isfile(resultFileName): 
            sublime.error_message("file already exists!")
            return;
        else:
            testFileName = codeForcesFolder+"test_data/"+programName+"/1.txt"
            create_empty_file(testFileName)
            self.window.open_file(testFileName)

            testFileName = codeForcesFolder+"test_data/"+programName+"/2.txt"
            create_empty_file(testFileName)
            self.window.open_file(testFileName)

            shutil.copyfile(codeForcesFolder+"codeforces_template.cpp", resultFileName)
            self.window.open_file(resultFileName)

            replaceRegex(codeForcesFolder+"codeforces_build_and_run.sh","PROGRAM=[a-zA-Z0-9_]+","PROGRAM="+programName)

