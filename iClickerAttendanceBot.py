import webbrowser

url = 'https://student.iclicker.com/#/login'

#open attendance site

chrome_path = 'open -a /Applications/Google\ Chrome.app %s'


webbrowser.get(chrome_path).open(url)