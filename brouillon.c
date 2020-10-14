if ((inf_draw.hero.forward.x >= 0 &&
        inf_draw.hero.forward.y >= 0 && sprite.ray.pos.x - sprite.pos.x <= 0 &&
        sprite.ray.pos.y - sprite.pos.y >= 0) 
        (inf_draw.hero.forward.x <= 0 && inf_draw.hero.forward.y >= 0 &&
        sprite.ray.pos.x - sprite.pos.x <= 0 &&
        sprite.ray.pos.y - sprite.pos.y <= 0) 
        (inf_draw.hero.forward.x >= 0 && inf_draw.hero.forward.y <= 0 &&
        sprite.ray.pos.x - sprite.pos.x >= 0 &&
        sprite.ray.pos.y - sprite.pos.y >= 0) ||
        (inf_draw.hero.forward.x <= 0 && inf_draw.hero.forward.y <= 0 &&
        sprite.ray.pos.x - sprite.pos.x >= 0 &&
        sprite.ray.pos.y - sprite.pos.y <= 0))