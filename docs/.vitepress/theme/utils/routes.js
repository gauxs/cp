import { withBase } from "vitepress";

/** Stable slug for JSON data files under public/data/topics/. */
export function topicDataSlug(topicId) {
  return topicId.replace(/\//g, "-");
}

/** Site page URL mirroring repo folder layout, e.g. algorithms/search/binary. */
export function topicPagePath(topicId) {
  return `/${topicId}`;
}

export function categoryPagePath(categoryId) {
  return `/${categoryId}`;
}

export function topicPageUrl(topicId) {
  return withBase(topicPagePath(topicId));
}

export function categoryPageUrl(categoryId) {
  return withBase(categoryPagePath(categoryId));
}
