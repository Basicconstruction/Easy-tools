C:\Apache\Anaconda38\envs\p1p\sip\PyQt5   全部文件夹copy,库文件？
C:\Apache\Anaconda38\envs\p1p\Lib\site-packages   PyQt5和pyqt_tools文件夹拷贝，python模块文件
C:\Apache\Anaconda38\envs\p1p\Scripts   pyqt5_tools可执行文件

注意，例子的python环境不一样,而且上面的是一个虚拟环境，下面的是个默认的conda环境

D:\Anaconda2021\Lib\site-packages\pyqt5_tools\Qt\bin\designer.exe 
qt designer
$FileDir$

pyuic
C:\ProgramData\Anaconda3\Scripts\pyuic5.exe
-o $FileNameWithoutExtension$.py $FileName$
$FileDir$

pyrcc
C:\ProgramData\Anaconda3\Scripts\pyrcc5.exe
$FileName$ -o $FileNameWithoutExtension$_rc.py
$FileDir$

python -m pip install PyQt5=12.6
