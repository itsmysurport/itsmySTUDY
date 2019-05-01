set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle.vim


call vundle#begin()
Plugin 'VundleVim/Vundle.vim'


Plugin 'vim-airline/vim-airline'

Plugin 'kien/ctrlp.vim'

Plugin 'xuhdev/SingleCompile'
nmap <F9> :SCCompile<cr>
nmap <F10> :SCCompileRun<cr>

Plugin 'scrooloose/nerdtree'
map <C-n> :NERDTreeToggle<CR>
let g:NERDTreeDirArrowExpandable = '▸'
let g:NERDTreeDirArrowCollapsible = '▾'
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif


Plugin 'plasticboy/vim-markdown'

Plugin 'scrooloose/syntastic'

Plugin 'wavded/vim-stylus'

Plugin 'Raimondi/delimitMate'

Plugin 'AutoComplPop'

" Plugin 'git://git.wincent.com/command-t.git'
" Plugin 'file:///home/gmarik/path/to/plugin'

Plugin 'taglist.vim'
nmap <C-n> :Tlist<CR>

Plugin 'MarcWeber/vim-addon-mw-utils'
Plugin 'tomtom/tlib_vim'
Plugin 'garbas/vim-snipmate'

call vundle#end()
filetype plugin indent on
