git add .
read -p 'Message for Commit: ' commitmsg
git commit -m "$commitmsg"
git push -u origin main