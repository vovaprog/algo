import sublime, sublime_plugin
import os.path
import shutil
import os

def create_empty_file(file_name):
    basedir = os.path.dirname(file_name)
    if not os.path.exists(basedir):
        os.makedirs(basedir)        
    open(file_name, 'a').close()

class CodeforcesNewPyCommand(sublime_plugin.WindowCommand):

    def run(self):
        self.window.show_input_panel("program name:", "", self.on_done, None, None)
        pass

    def on_done(self, text):
        line = text

        codeForcesFolder = "/mnt/programs/programs/learn 2015/learn_algorithms/codeforces_archive/";

        programName = line

        resultFileName = codeForcesFolder+programName+".py";
        
        if os.path.isfile(resultFileName): 
            sublime.error_message("file already exists!")
            return;
        else:
            testFileName = codeForcesFolder+"test_data/"+programName+".py/1.txt"
            create_empty_file(testFileName)
            self.window.open_file(testFileName)

            testFileName = codeForcesFolder+"test_data/"+programName+".py/2.txt"
            create_empty_file(testFileName)
            self.window.open_file(testFileName)

            shutil.copyfile(codeForcesFolder+"codeforces_template.py", resultFileName)
            self.window.open_file(resultFileName)


