# .bashrc

alias rm='rm -I'
alias lm='ls -al'
alias ll='ls -l'
alias l='ls -l'
alias rm='rm -i'
#alias word='sdcv'
alias check_port='netstat -antlpe'
alias ps_tree='ps aux --forest'
alias cls=clear
alias cl=cls
alias csl=cls
alias cs=cls
alias csl=cls
alias c=cls
alias dstat='dstat -cdlmnpsy'
alias ..='cd ..'
alias ...='cd ../..'
alias ....='cd ../../..'

if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

if [ -f /etc/bash_completion ]; then
	. /etc/bash_completion
fi

alias memcheck='valgrind --quiet --verbose --tool=memcheck --leak-check=full'

PS1='\[\033[01;32m\]\u@\h\[\033[00m\] \[\033[01;34m\]\W\[\033[00m\]\\$ '

export HISTCONTROL=ignorespace

export LS_COLORS='no=00:fi=00:di=01;34:ln=01;36:pi=40;33:so=01;35:bd=40;33;01:cd=40;33;01:or=01;05;37;41:mi=0 1;05;37;41:ex=01;32:*.cmd=01;32:*.exe=01;32:*.com=01;32:*.btm=01;32:*.bat=01;32:*.sh=01;32:*.csh=01;32 :*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.gz=01;3 1:*.bz2=01;31:*.bz=01;31:*.tz=01;31:*.rpm=01;31:*.cpio=01;31:*.jpg=01;35:*.gif=01;35:*.bmp=01;35:*.xbm =01;35:*.xpm=01;35:*.png=01;35:*.tif=01;35:'

if [ -e /usr/bin/vimx ]; then 
	alias vim='/usr/bin/vimx' 
fi

#poem_print
