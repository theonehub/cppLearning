" Gotta be first
set nocompatible

filetype off

set rtp+=~/.vim/bundle/Vundle.vim
let g:clang_library_path='/home/ankit/.vim/bundle/youcompleteme/third_party/ycmd/third_party/clang/lib/libclang.so.10'
call vundle#begin()

Plugin 'gmarik/Vundle.vim'
Plugin 'tpope/vim-fugitive'
Plugin 'rip-rip/clang_complete'
Plugin 'altercation/vim-colors-solarized'
Plugin 'tomasr/molokai'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'scrooloose/nerdtree'
Plugin 'jistr/vim-nerdtree-tabs'
Plugin 'valloric/youcompleteme'
call vundle#end()

filetype plugin indent on

" --General Setting---
set backspace=indent,eol,start
set ruler
set number
set showcmd
set incsearch
set hls
set expandtab
set ts=4
set sw=4
map <F2> :retab <CR> :wq! <CR>

syntax on

"set mouse=a

" ----- Plugin-Specific Settings --------------------------------------

" ----- altercation/vim-colors-solarized settings -----
" Toggle this to "light" for light colorscheme
set background=dark

" Uncomment the next line if your terminal is not configured for solarized
"let g:solarized_termcolors=256

" Set the colorscheme
colorscheme solarized


" ----- bling/vim-airline settings -----
" Always show statusbar
set laststatus=2

" Fancy arrow symbols, requires a patched font
" To install a patched font, run over to
"     https://github.com/abertsch/Menlo-for-Powerline
" download all the .ttf files, double-click on them and click "Install"
" Finally, uncomment the next line
"let g:airline_powerline_fonts = 1

" Show PASTE if in paste mode
let g:airline_detect_paste=1

" Show airline for tabs too
let g:airline#extensions#tabline#enabled = 1

let @c="i/**\<CR>Tips________________________________________________________________________\<CR>Tips|                                                                      |\<CR>Tips|                                                                      |\<CR>Tips|______________________________________________________________________|\<CR>\x*/\<CR>\<Esc>"
