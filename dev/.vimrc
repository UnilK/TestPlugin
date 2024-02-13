"compile
map mk :silent !dev/compile<CR><C-l>

"run
map ml :silent !dev/run<CR><C-l>

"switch to headerfile. <C-o> switches back to source.
map <C-h> G/include<CR> :noh<CR> w w gf

"included jump paths
set path=Source,~/JUCE/modules,JuceLibraryCode

"close tabs by holding down q
nmap qqq :qa<CR>

"ctags
execute "set <C-S-M-q>=\eq"
execute "set <C-S-M-e>=\ee"
imap <C-S-M-q> :ptag <C-r><C-w><CR>
imap <C-S-M-e> :pc<CR>
nmap <C-S-M-q> :ptag <C-r><C-w><CR>
nmap <C-S-M-e> :pc<CR>

"presistent undo
let undo_path = expand("./dev/.undo")
if !isdirectory(undo_path)
    call system("mkdir -p ./dev/.undo")
endif
let &undodir = undo_path

set undofile
autocmd BufEnter * set undofile
autocmd BufAdd * set undofile
autocmd BufNew * set undofile
autocmd BufRead * set undofile
autocmd BufWinEnter * set undofile

