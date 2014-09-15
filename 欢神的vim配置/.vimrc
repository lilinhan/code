"-------------------------------------------------------------------
"
" -- VIM 配置文件 .vimrc
"
"
"     作者: hurley  （其实就是这里抄一点，那里抄一点，文档里学一点）
"
"     博客：http://www.0xffffff.org
"
"     最后修改时间：2013-5-25
"
"-------------------------------------------------------------------

set autoread 			 " 正在编辑文件被其他程序改动时自动重新加载
syntax on  	         	 " 使用语法高亮
filetype plugin indent on 	 " 打开文件类型检测
set nocp 			 " 使用不兼容 vi 的模式（vi模式一些操作很不方便）
set autoindent       		 " 设置自动对齐(缩进)：即每行的缩进值与上一行相等；使用 noautoindent 取消设置
set smartindent        		 " 智能对齐方式
set wrap 			 " 自动换行
set linebreak 			 " 整词换行
" 个人不喜欢4个空格的缩进
"set tabstop=4 			 " 设置制表符(tab键)的宽度
"set softtabstop=4     	 	 " 设置软制表符的宽度    
"set shiftwidth=4       	 " (自动) 缩进使用的4个空格
set cindent              	 " 使用 C/C++ 语言的自动缩进方式
set cinoptions={0,1s,t0,n-2,p2s,(03s,=.5s,>1s,=1s,:1s     " 设置C/C++语言的具体缩进方式
set backspace=2          	 " 设置退格键可用
set mouse=a              	 " 使用鼠标
set number              	 " 显示行号
set cul				 " 显示当前行下划线
colorscheme ron			 " 设置配色方案

let g:indentLine_color_term=239
let g:indentLine_char='¦'

au BufNewFile,BufRead *.py,*.pyw,*.wsgi setf python
au BufNewFile,BufRead *.inc setf asm

" MiniBufferExplorer 的设置
let g:miniBufExplMapWindowNavVim=1 		" 按下Ctrl+h/j/k/l，可以切换到当前窗口的上下左右窗口
let g:miniBufExplMapWindowNavArrows=1 		" 按下Ctrl+箭头，可以切换到当前窗口的上下左右窗口
let g:miniBufExplMapCTabSwitchBufs=1 		" Ctrl+tab移到下一个窗口；Ctrl+Shift+tab移到上一个窗口
let g:miniBufExplModSelTarget=1    		" 不要在不可编辑内容的窗口（如TagList窗口）中打开选中的buffer

" 设置分屏浏览
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<CR>

" 修改Zen Coding 默认的快捷键映射
imap <C-e> <C-y>,

" 符号配对
" function ClosePair(char)
" 	if getline('.')[col('.') - 1] == a:char
" 		return "\<Right>"
" 	elseif (a:char == "\'" || a:char == "\"")
" 		return a:char.a:char."\<left>"
" 	else
" 		return a:char
" 	endif
" endf

" 设置键映射
" 很无奈下面的小括号匹配和 echofunc 插件不兼容....
" 虽然这里注释掉了，但是通过修改 echofunc 插件代码在插件内成功实现...^ ^
" inoremap ( ()<ESC>i
" inoremap ) <c-r>=ClosePair(')')<CR>
" inoremap { {}<ESC>i<CR><ESC>V<O
 inoremap { {}<ESC>i
" inoremap } <c-r>=ClosePair('}')<CR>
 inoremap [ []<ESC>i
" inoremap ] <c-r>=ClosePair(']')<CR>
" inoremap " ""<ESC>i
" inoremap ' ''<ESC>i

" 设置超级TAB的补全
let g:SuperTabRetainCompletionType=0
let g:SuperTabDefaultCompletionType="<C-X><C-U>"

"golang 自动补全
autocmd Filetype go let g:SuperTabDefaultCompletionType="<C-x><C-o>"

" 自动补全列表的颜色设置
highlight Pmenu ctermfg=black 
highlight PmenuSel ctermfg=white ctermbg=black

" clang_complete 自动补全插件设置
set completeopt=longest,menu
let g:clang_complete_copen=0
let g:clang_auto_select=1
let g:clang_complete_auto=1
let g:clang_complete_macros=1
let g:clang_use_library=1
"let g:clang_user_options="-std=c++11"

" Java 自动补全设置
autocmd Filetype java set omnifunc=javacomplete#Complete
autocmd Filetype java set completefunc=javacomplete#CompleteParamsInfo

" Python 自动补全
let g:pydiction_location = '~/.vim/python/complete-dict'

" 显示历史打开文件
map <F3> :MRU<CR>
imap <F3> <ESC>:MRU<CR>

" F4 切换粘贴和非粘贴模式
set pastetoggle=<F4>

" ctags 相关设置

" 按下F5，在当前目录递归生成tag文件
map <F5> :!ctags -R<CR><CR>
imap <F5> <ESC>:!ctags -R<CR><CR>

" vim 启动时自动载入以下tags文件
set tags=tags
set tags+=./tags

"set tags+=/usr/local/src/linux-2.6.32.61/tags
"set tags+=/usr/local/src/linux-3.12.6/tags
"set tags+=/usr/local/src/bash-4.2/tags
"set tags+=/usr/include/tags
"set tags+=/usr/include/bits/tags
"set tags+=/usr/include/sys/tags
"set tags+=/usr/include/linux/tags
"set tags+=/usr/include/arpa/tags
"set tags+=/usr/include/netinet/tags
set tags+=/usr/include/c++/4.7.2/tags
set tags+=/usr/include/Qt/tags
set tags+=/usr/include/Qt3Support/tags
set tags+=/usr/include/QtCore/tags
set tags+=/usr/include/QtDBus/tags
set tags+=/usr/include/QtDeclarative/tags
set tags+=/usr/include/QtDesigner/tags
set tags+=/usr/include/QtGui/tags
set tags+=/usr/include/QtHelp/tags
set tags+=/usr/include/QtMultimedia/tags
set tags+=/usr/include/QtNetwork/tags
set tags+=/usr/include/QtOpenGL/tags
set tags+=/usr/include/QtScript/tags
set tags+=/usr/include/QtScriptTools/tags
set tags+=/usr/include/QtSql/tags
set tags+=/usr/include/QtSvg/tags
set tags+=/usr/include/QtTest/tags
set tags+=/usr/include/QtUiTools/tags
set tags+=/usr/include/QtXml/tags
set tags+=/usr/include/QtXmlPatterns/tags

" 系统剪贴板映射 
set clipboard=unnamedplus
map <C-y> "+y
map <C-p> "+p

" QuickFix 插件的设置

" 按下F6，执行make编译程序，并打开quickfix窗口，显示编译信息
map <F6> :make<CR><CR><CR> :copen<CR><CR>
" 按下F7，光标移到上一个错误所在的行
map <F7> :cp<CR>
" 按下F8，光标移到下一个错误所在的行
map <F8> :cn<CR>
" 按下F9，执行make clean
map <F9> :make clean<CR><CR><CR>

" 以下的映射是使上面的快捷键在插入模式下也能用
imap <F6> <ESC>:make clean<CR><CR><CR>
imap <F7> <ESC>:make<CR><CR><CR> :copen<CR><CR>
imap <F8> <ESC>:cp<CR>
imap <F9> <ESC>:cn<CR>

" 按下F10，在当前代码的 .c / .h 之间切换
nnoremap <silent> <F10> :A<CR>

" powerline 配置
set nocompatible
set laststatus=2
set encoding=utf-8
set t_Co=256
set guifont=PowerlineSymbols\ for\ Powerline 
let g:Powerline_symbols='unicode'

" 预防手误的杀招
cnoremap Q! q!
cnoremap Q1 q!
command  Q  q
command  Wq wq
command  WQ wq
command  W  w

function! Mydict()
let expl=system('sdcv -n ' . expand("<cword>"))
windo if expand("%")=="dict-tmp" |q!|endif	
30vsp dict-tmp
setlocal buftype=nofile bufhidden=hide noswapfile
1s/^/\=expl/
wincmd p
endf

"按键绑定，将调用函数并执行
map f :call Mydict()<CR><C-j><C-l>

