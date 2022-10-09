#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H


class TextureHolder
{
    public:
        TextureHolder();
        virtual ~TextureHolder();
        void load(Textures::ID id, const std::string& filename);
        sf::Texture& get(Textures::ID id);
        const sf::Texture& get(Textures::ID id) const;



    private:
        std::map<Textures::ID,std::unique_ptr<sf::Texture>> mTextureMap;
};

#endif // TEXTUREHOLDER_H
