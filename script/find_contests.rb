# gem install codeforces
require "codeforces"

Codeforces.contests.rounds.div2.slice(0, 346-200).reverse.each do |c|
  puts "* [ ] [#{c.name}](http://codeforces.com/contest/#{c.id})"
end
