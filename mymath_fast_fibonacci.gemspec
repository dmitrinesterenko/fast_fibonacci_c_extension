Gem::Specification.new do |s|
  s.name = "mymath_fast_fibonacci"
  s.version = "0.0.1"
  s.summary = "Fast fibonacci for Ruby"
  s.author = "Dmitri Nesterenko"
  s.files = Dir.glob("ext/**/*.{c,rb}) + 
            Dir.glob("lib/**/*.rb")

  s.extensions << "ext/mymath_fast_fibonacci/extconf.rb"
  s.add_development_dependency "rake-compiler"
end
